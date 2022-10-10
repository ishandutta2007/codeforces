// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456780LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N,W;
    cin >> N >> W;
    vector< pair< pair<long long,long long>,int > > A(N);
    for(int i =0; i < N; i++) {
        cin >> A[i].ff.ff >> A[i].ff.ss;
        A[i].ss =i;}
    vector< pair<long long,int> > B(N);
    for(int i =0; i < N; i++) B[i].ff =A[i].ff.ss, B[i].ss =i;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    int ansA =-1;
    long long ans =0;
    vector<bool> is2(N,false);
    set< pair<long long,int> > M;
    set< pair<long long,int> > M2;
    for(int i =0; i < (W+1)/2; i++) {
        ans +=B[i].ff;
        is2[B[i].ss] =true;
        M.insert(make_pair(B[i].ff,B[i].ss));}
    int ansB =M.size(), ansC =0;
    for(int i =0; i < N; i++) if(!is2[A[i].ss]) M2.insert(make_pair(A[i].ff.ss,A[i].ss));
    long long akt =ans;

    set< pair<long long,int> > M1;
    set< pair<long long,int> > M02;
    for(int i =0; i < N; i++) {
        if(is2[A[i].ss]) {
            M.erase(M.find(make_pair(A[i].ff.ss,A[i].ss)));
            akt -=A[i].ff.ss;
            is2[A[i].ss] =false;}
        else M2.erase(M2.find(make_pair(A[i].ff.ss,A[i].ss)));
        akt +=A[i].ff.ff;
        M1.insert(make_pair(A[i].ff.ss-A[i].ff.ff,A[i].ss));
        int w =M.size()*2+(i+1)+M02.size();
        while(w < W && !M2.empty()) {
            akt +=M2.begin()->ff;
            w +=2;
            is2[M2.begin()->ss] =true;
            M.insert(*M2.begin());
            M2.erase(M2.begin());}
        while(w < W && !M1.empty()) {
            akt +=M1.begin()->ff;
            w++;
            M02.insert(*M1.begin());
            M1.erase(M1.begin());}
        while(w >= W+2 && !M.empty() && M02.size() >= 2) {
            long long a =(*M.rbegin()).ff, b =(*M02.rbegin()).ff+(*(--M02.rbegin())).ff;
            w -=2;
            if(a >= b) {
                is2[(*M.rbegin()).ss] =false;
                akt -=a;
                M2.insert(*M.rbegin());
                M.erase(--M.end());}
            else {
                akt -=b;
                M1.insert(*M02.rbegin());
                M02.erase(--M02.end());
                M1.insert(*M02.rbegin());
                M02.erase(--M02.end());}
            }
        while(w >= W+2 && !M.empty()) {
            w -=2;
            is2[(*M.rbegin()).ss] =false;
            akt -=(*M.rbegin()).ff;
            M2.insert(*M.rbegin());
            M.erase(--M.end());}
        while(w >= W+1 && !M02.empty()) {
            w--;
            akt -=(*M02.rbegin()).ff;
            M1.insert(*M02.rbegin());
            M02.erase(--M02.end());}
        while(!M1.empty() && !M02.empty() && M1.begin()->ff < M02.rbegin()->ff) {
            akt -=M02.rbegin()->ff-M1.begin()->ff;
            M1.insert(*M02.rbegin());
            auto jt =M02.end(); jt--;
            M02.erase(jt);
            M02.insert(*M1.begin());
            M1.erase(M1.begin());}
        while(!M2.empty() && !M.empty() && M2.begin()->ff < M.rbegin()->ff) {
            is2[M.rbegin()->ss] =false;
            is2[M2.begin()->ss] =true;
            akt -=M.rbegin()->ff-M2.begin()->ff;
            M2.insert(*M.rbegin());
            auto jt =M.end(); jt--;
            M.erase(jt);
            M.insert(*M2.begin());
            M2.erase(M2.begin());}

        while(w > W && !M.empty() && !M1.empty()) {
            long long a =M.rbegin()->ff, b =M1.begin()->ff;
            if(a <= b) break;
            akt -=a-b;
            w--;
            is2[M.rbegin()->ss] =false;
            M2.insert(*M.rbegin());
            M.erase(--M.end());
            M02.insert(*M1.begin());
            M1.erase(M1.begin());}

        while(w >= W && !M.empty() && M1.size() >= 2) {
            long long a =M.rbegin()->ff, b =M1.begin()->ff+(++M1.begin())->ff;
            if(a <= b) break;
            akt -=a-b;
            is2[M.rbegin()->ss] =false;
            M2.insert(*M.rbegin());
            M.erase(--M.end());
            M02.insert(*M1.begin());
            M1.erase(M1.begin());
            M02.insert(*M1.begin());
            M1.erase(M1.begin());}


        while(w >= W && !M2.empty() && M02.size() >= 2) {
            long long a =M2.begin()->ff, b =M02.rbegin()->ff+(++M02.rbegin())->ff;
            if(a >= b) break;
            akt -=b-a;
            is2[M2.begin()->ss] =true;
            M.insert(*M2.begin());
            M2.erase(M2.begin());
            M1.insert(*M02.rbegin());
            M02.erase(--M02.end());
            M1.insert(*M02.rbegin());
            M02.erase(--M02.end());}

        if(w >= W) {
            ans =min(ans,akt);
            if(ans == akt) {ansA =i; ansB =M.size(), ansC =M02.size();}}
        }

    cout << ans << "\n";
    M.clear();
    M02.clear();
    for(int i =ansA+1; i < N; i++) M.insert(make_pair(A[i].ff.ss,A[i].ss));
    for(int i =0; i <= ansA; i++) M02.insert(make_pair(A[i].ff.ss-A[i].ff.ff,A[i].ss));
    vector<int> ansX(N,0);
    for(int i =0; i <= ansA; i++) ansX[A[i].ss] =1;
    while(ansB > 0) {
        ansX[M.begin()->ss] =2;
        ansB--;
        M.erase(M.begin());}
    while(ansC > 0) {
        ansX[M02.begin()->ss] =2;
        ansC--;
        M02.erase(M02.begin());}
    for(int i =0; i < N; i++) cout << ansX[i];
    cout << "\n";
    return 0;}

// look at my code
// my code is amazing