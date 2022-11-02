#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 3e5+10;
const int INF = 1e6;

int N, K;
string S;
vector<int> G[n];
int s[n], c[n];
ll op[n][2];
bool cb[n];

void printAll(){
  for(int i=0; i<N; i++){
    cout << "s: " << s[i] << " c: " << c[i] << " op: " << op[i][0] << "," << op[i][1] << " cb: " << cb[i] << endl;
  }
  cout << endl;
}

pii find(int cur, int val){
  if(c[cur] == cur)
    return make_pair(cur, val);
  pii res = find(c[cur], cb[cur]);
  cb[cur] = res.second;
  c[cur] = res.first;
  return make_pair(c[cur], cb[cur]^val);
}

ll calc(int x){
  return min(op[x][0], op[x][1]);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  cin >> S;
  for(int i=0; i<K; i++){
    int C;
    cin >> C;
    for(int j=0; j<C; j++){
      int x;
      cin >> x;
      x--;
      G[x].push_back(i);
    }
  }
  for(int i=0; i<n; i++){
    c[i] = i;
    op[i][0] = 0;
    op[i][1] = 1;
    cb[i] = false;
    s[i] = 1;
  }
  ll curCnt = 0;
  for(int i=0; i<N; i++){
    if(sz(G[i]) == 1){
      int x = G[i][0];
      int ind, val;
      tie(ind, val) = find(x, S[i]!='1');
      curCnt -= calc(ind);
      op[ind][1-val] = INF;
      curCnt += calc(ind);
    }
    else if(sz(G[i]) == 2){
      int a = G[i][0], b = G[i][1];
      int chg = S[i] == '0' ? 1 : 0;
      int ind1, val1;
      tie(ind1, val1) = find(a, 0);
      int ind2, val2;
      tie(ind2, val2) = find(b, chg);
      if(ind1 != ind2){
        curCnt -= calc(ind1);
        curCnt -= calc(ind2);
        if(s[ind1] < s[ind2]){
          swap(ind1, ind2);
          swap(val1, val2);
          swap(a, b);
        }
        //cb[ind2] = S[i]=='0';
        s[ind1] += s[ind2];
        op[ind1][val1] += op[ind2][val2];
        op[ind1][1-val1] += op[ind2][1-val2];
        c[ind2] = ind1;
        cb[ind2] = (val1+val2)%2;
        curCnt += calc(ind1);
      }
    }
    //printAll();
    cout << curCnt << "\n";
  }

  return 0;
}