#include<iostream>
#include<map>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

struct team {
  string name;
  int pts;
  int goal, miss;
};

bool operator < (const team& a, const team& b)
{
  if(a.pts < b.pts) return true;
  else if(a.pts > b.pts) return false;
  if(a.goal-a.miss < b.goal-b.miss) return true;
  else if(a.goal-a.miss > b.goal-b.miss) return false;
  if(a.goal < b.goal) return true;
  else if(a.goal > b.goal) return false;
  return false;
}

int main()
{
  map<string, team> T;
  int N;
  cin >> N;
  for(int i=0; i<N; ++i) {
    string s;
    cin >> s;
    T[s].name = s;
    T[s].pts = T[s].goal = T[s].miss = 0;
  }
  for(int i=0; i<N*(N-1)/2; ++i) {
    string p, q;
    cin >> p >> q;
    string n1, n2;
    int pos = p.find('-');
    n1 = p.substr(0, pos);
    n2 = p.substr(pos+1);
    int pts1, pts2;
    pos = q.find(':');
    pts1 = atoi(q.substr(0, pos).c_str());
    pts2 = atoi(q.substr(pos+1).c_str());
    // cout << n1 << "-" << n2 << " " << pts1 << ":" << pts2 << endl;
    if(pts1 > pts2) {
      T[n1].pts += 3;
    }
    if(pts1 < pts2) {
      T[n2].pts += 3;
    }
    if(pts1 == pts2) {
      T[n1].pts++;
      T[n2].pts++;
    }
    T[n1].goal += pts1; T[n1].miss += pts2;
    T[n2].goal += pts2; T[n2].miss += pts1;
  }
  vector<team> tt;
  for(map<string, team>::iterator it = T.begin(); it != T.end(); ++it) {
    tt.push_back(it->second);
  }
  sort(tt.begin(), tt.end());
  vector<string> sol;
  for(int i=0; i<N/2; ++i)
    sol.push_back(tt[N-i-1].name);
  sort(sol.begin(), sol.end());
  for(int i=0; i<sol.size(); ++i)
    cout << sol[i] << endl;
  return 0;
}