#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, t) for (int i = s; i < t; ++i)
#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)

#define sz(x) (int)(x).size()
#define LL long long
#define mp make_pair
#define pb push_back

//  Source code: https://github.com/jtilly/matchingR/blob/master/src/roommate.cpp
//  matchingR -- Matching Algorithms in R and C++
//
//  Copyright (C) 2015  Jan Tilly <jtilly@econ.upenn.edu>
//                      Nick Janetos <njanetos@econ.upenn.edu>
//
//  This file is part of matchingR.
//
//  matchingR is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 2 of the License, or
//  (at your option) any later version.
//
//  matchingR is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.


// [[Rcpp::depends(RcppArmadillo)]]

//' Computes a stable roommate matching
//'
//' This is the C++ wrapper for the stable roommate problem. Users should not
//' call this function directly, but instead use
//' \code{\link{roommate}}.
//' 
//' @param pref is a matrix with the preference order of each individual in the
//'   market. If there are \code{n} individuals, then this matrix will be of
//'   dimension \code{n-1} by \code{n}. The \code{i,j}th element refers to
//'   \code{j}'s \code{i}th most favorite partner. Preference orders must be
//'   specified using C++ indexing (starting at 0). The matrix \code{pref} must
//'   be of dimension \code{n-1} by \code{n}.
//' @return A vector of length \code{n} corresponding to the matchings that were
//'   formed (using C++ indexing). E.g. if the \code{4}th element of this vector
//'   is \code{0} then individual \code{4} was matched with individual \code{1}.
//'   If no stable matching exists, then this function returns a vector of
//'   zeros.
//'  @export
// [[Rcpp::export]]
int matchings[2001];
int pref[2001][2001];

int revpos[2001][2001];

void cpp_wrapper_irving(int N) {
    int proposal_to[N];
    int proposal_from[N];
    int proposed_to[N];

    // All participants begin unmatched having proposals accepted by nobody (=N)...
    FOR(i, 0, N) proposal_to[i] = N;
    // having accepted proposals from nobody (=N)...
    FOR(i, 0, N) proposal_from[i] = N;
    // and having proposed to nobody.
    FOR(i, 0, N) proposed_to[i] = 0;

    bool stable = false;
    while (!stable) {
        // set stable to false later if anyone hasn't proposed / been proposed to
        stable = true;
        for (int n = 0; n < N; n++) {
            // n proposes to the next best guy if he hasn't proposed to everyone already...
            if (proposed_to[n] >= N-1) { return; }

            // or if he has no proposals accepted by anyone.
            if (proposal_to[n] == N) {

                // find the player he is proposing to next
                int proposee = pref[n][proposed_to[n]];


                // find proposee's opinion of the proposer (lower is better)
                int op = revpos[proposee][n];

                // find proposee's opinion of his current match
                // lower is better
                // unmmatched is N
                int op_curr = N;
                
                if (proposal_from[proposee] != N) {
                	op_curr = revpos[proposee][proposal_from[proposee]];
                }

                // if the next best guy likes him he accepts
                if (op < op_curr) {

                    // make the proposal
                    proposal_to[n] = proposee;
                    // reject the proposee's original proposer's proposal
                    // got it!?
                    if (proposal_from[proposee] != N) {
                        proposal_to[proposal_from[proposee]] = N;
                        // someone has proposed to nobody, we're not stabler yet
                        stable = false;
                    }
                    // record the proposal
                    proposal_from[proposee] = n;
                } else {
                    // offer was rejected, we're not stable yet
                    stable = false;
                }

                // iterate n's proposal forward
                proposed_to[n]++;
            }
        }
    }

    // Generate tables, initially of length N
    std::vector< std::deque<int> > table(N, std::deque<int>(N-1));
    for (int n = 0; n < N; ++n) {
        for (int i=0; i<N-1; i++) {
            // fill in the table with preferences
            table[n][i] = pref[n][i];
        }
    }

    // Delete entries we eliminated in round 1
    for (int n = 0; n < N; n++) {
        for (int i = table[n].size()-1; i>= 0; i--) {
            if (table[n][i] == proposal_from[n]) {
                break;
            } else {
                if (table[n].size() == 0) { return; }
                // find and erase from the table
                bool erased = false;
                for (int j = 0; j < table[table[n].back()].size(); j++) {
                    if (table[table[n].back()][j] == n) {
                        table[table[n].back()].erase(table[table[n].back()].begin() + j);
                        erased = true;
                        break;
                    }
                }
                if (!erased) { return; }
                table[n].pop_back();
            }
        }
    }

    // Eliminate rotations
    // A 'rotation' is a series of individuals and preference pairs which satisfy
    // a relationship specified in Irving (1985). Removing a rotation maintains the
    // status of the table as a 'stable' table, meaning everyone's most preferred
    // feasible option hates them.
    stable = false;
    while(!stable) {
        stable = true;
        for (int n = 0; n < N; n++) {
            if (table[n].size() > 1) {
                stable = false;
                std::vector<int> x;
                std::vector<int> index;

                int new_index = n;
                // Unassigned for now, so assign to the maximum value
                int rot_tail = static_cast<int>(-1);

                while (rot_tail == (int) (index.end() - index.begin() - 1)) {
                    int new_x = table[new_index][1];
                    new_index = table[new_x].back();

                    // Check for a rotation
                    rot_tail = find(index.begin(), index.end(), new_index) - index.begin();

                    x.push_back(new_x);
                    index.push_back(new_index);
                }

                // Delete the rotation
                for (int i = rot_tail + 1; i < index.size(); i++) {
                    while(table[x[i]].back() != index[i-1]) {
                        // find and erase from the table
                        // x[i] needs to be removed from  table[table[x[i]].back()], and
                        // table[table[x[i]].back()][x[i]] needs to be removed from
                        // table[x[i]].
                        int tab_size = table[table[x[i]].back()].size();

                        // Remove x[i] from table[table[x[i]].back()]
                        // If x[i] is not in table[table[x[i]].back()], then it should remove
                        // nothing.
                        // This uses an 'erase-remove' idiom from the std library.
                        table[table[x[i]].back()].erase(std::remove(table[table[x[i]].back()].begin(),
                                                        table[table[x[i]].back()].end(),
                                                        x[i]),
                                                        table[table[x[i]].back()].end());

                        // Check to see if it removed x[i] or not (whether the table's the same size)
                        if (tab_size == table[table[x[i]].back()].size()) { return; }

                        // Check to see if there's only one element remaining (if so, no stable matching.)
                        if (table[x[i]].size() == 1) { return; }

                        // Remove table[table[x[i]].back()][x[i]] from table[x[i]] (it should be at the end).
                        table[x[i]].pop_back();
                    }
                }
            }
        }
    }

    // Check if anything is empty
    for (int i = 0; i < table.size(); i++) {
        if (table[i].empty()) { return; }
    }

    // Create the matchings
    for (int n = 0; n < N; n++) {
        matchings[n] = table[n][0];
    }

    return ;
}

#define K 2001

int n;
int a[K][K];

int exi[K], ans[K]; 

vector<pair<int, int> > V;

int main() {
	scanf("%d", &n);
	
	FOE(i, 1, n) FOE(j, 1, n) if (i != j) scanf("%d", &a[i][j]);
	
	if (n % 2) {
		puts("-1");
		return 0;	
	}
	
	FOE(i, 1, n) {
		V.clear();
		FOE(j, 1, n) if (i != j) V.pb(mp(a[i][j], j));
		sort(V.begin(), V.end());
		
		FOR(j, 0, V.size()) {
			int id = V[j].second;
			pref[i - 1][j] = id - 1;
			revpos[i - 1][id - 1] = j;
		}
	}
	
	cpp_wrapper_irving(n);
	
	int ok = 0;
	FOE(i, 1, n) if (matchings[i] != 0) ok = 1; 
	
	if (!ok) {
		puts("-1");
		return 0;	
	}
	
	FOE(i, 1, n) {
		printf("%d\n", matchings[i - 1] + 1);	
	}
}