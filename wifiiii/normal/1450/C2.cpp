#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;


char a[305][305],aa[305][305],aaa[305][305];
char b[305][305];
int chk(int n) {
    for(int i=1;i<=n-2;++i) {
        for(int j=1;j<=n-2;++j) {
            if(a[i][j]=='X' && a[i][j+1]=='X' && a[i][j+2]=='X') return 0;
            if(a[i][j]=='O' && a[i][j+1]=='O' && a[i][j+2]=='O') return 0;
            swap(i,j);
            if(a[i][j]=='X' && a[i][j+1]=='X' && a[i][j+2]=='X') return 0;
            if(a[i][j]=='O' && a[i][j+1]=='O' && a[i][j+2]=='O') return 0;
            swap(i,j);
        }
    }
    return 1;
}
void rotate(int n, int k) {
    ii ji aaa[i][j]=a[i][j];
    while(k--) {
        ii ji aa[i][j]=aaa[n+1-j][i];
        ii ji aaa[i][j]=aa[i][j];
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
//        ii ji {int tmp=mrand()%3;if(tmp==0) a[i][j]='.';else if(tmp==1)a[i][j]='X';else a[i][j]='O';};
        ii ji cin>>a[i][j];
        ii ji b[i][j]=a[i][j];
        int tot=0;
        ii ji if(a[i][j]=='X' || a[i][j]=='O') ++tot;
        int lim=tot/3,ok=0,x,y;
        for(int r2=0;r2<3&&!ok;++r2)
            for(int r=0;r<3&&!ok;++r) {
                if(r==r2) continue;
                for(int k=0;k<4;++k) {
                    rotate(n,k+4);
                    int cnt=0;
                    for(int i=1;i<=n;++i) {
                        for(int j=1;j<=n;++j) {
                            if((i+j)%3==r && aa[i][j]=='X') {
                                int l=j,r=j;
                                while(l>=1 && aa[i][l]=='X') --l;++l;
                                while(r<=n && aa[i][r]=='X') ++r;--r;
                                int l2=i,r2=i;
                                while(l2>=1 && aa[l2][j]=='X') --l2;++l2;
                                while(r2<=n && aa[r2][j]=='X') ++r2;--r2;
                                if(r2-l2>=2 || r-l>=2) {
                                    ++cnt;
                                    aa[i][j]='O';
                                }
                            }
                        }
                    }
                    for(int i=1;i<=n;++i) {
                        for(int j=1;j<=n;++j) {
                            if((i+j)%3==r2 && aa[i][j]=='O') {
                                int l=j,r=j;
                                while(l>=1 && aa[i][l]=='O') --l;++l;
                                while(r<=n && aa[i][r]=='O') ++r;--r;
                                int l2=i,r2=i;
                                while(l2>=1 && aa[l2][j]=='O') --l2;++l2;
                                while(r2<=n && aa[r2][j]=='O') ++r2;--r2;
                                if(r2-l2>=2 || r-l>=2) {
                                    ++cnt;
                                    aa[i][j]='X';
                                }
                            }
                        }
                    }
                    for(int i=1;i<=n;++i) {
                        for(int j=1;j<=n;++j) {
                            if((i+j)%3==r && aa[i][j]=='X') {
                                int l=j,r=j;
                                while(l>=1 && aa[i][l]=='X') --l;++l;
                                while(r<=n && aa[i][r]=='X') ++r;--r;
                                int l2=i,r2=i;
                                while(l2>=1 && aa[l2][j]=='X') --l2;++l2;
                                while(r2<=n && aa[r2][j]=='X') ++r2;--r2;
                                if(r2-l2>=2 || r-l>=2) {
                                    ++cnt;
                                    aa[i][j]='O';
                                }
                            }
                        }
                    }
                    for(int i=1;i<=n;++i) {
                        for(int j=1;j<=n;++j) {
                            if((i+j)%3==r2 && aa[i][j]=='O') {
                                int l=j,r=j;
                                while(l>=1 && aa[i][l]=='O') --l;++l;
                                while(r<=n && aa[i][r]=='O') ++r;--r;
                                int l2=i,r2=i;
                                while(l2>=1 && aa[l2][j]=='O') --l2;++l2;
                                while(r2<=n && aa[r2][j]=='O') ++r2;--r2;
                                if(r2-l2>=2 || r-l>=2) {
                                    ++cnt;
                                    aa[i][j]='X';
                                }
                            }
                        }
                    }
                    for(int i=1;i<=n;++i) {
                        for(int j=1;j<=n;++j) {
                            if((i+j)%3==r && aa[i][j]=='X') {
                                int l=j,r=j;
                                while(l>=1 && aa[i][l]=='X') --l;++l;
                                while(r<=n && aa[i][r]=='X') ++r;--r;
                                int l2=i,r2=i;
                                while(l2>=1 && aa[l2][j]=='X') --l2;++l2;
                                while(r2<=n && aa[r2][j]=='X') ++r2;--r2;
                                if(r2-l2>=2 || r-l>=2) {
                                    ++cnt;
                                    aa[i][j]='O';
                                }
                            }
                        }
                    }
                    for(int i=1;i<=n;++i) {
                        for(int j=1;j<=n;++j) {
                            if((i+j)%3==r2 && aa[i][j]=='O') {
                                int l=j,r=j;
                                while(l>=1 && aa[i][l]=='O') --l;++l;
                                while(r<=n && aa[i][r]=='O') ++r;--r;
                                int l2=i,r2=i;
                                while(l2>=1 && aa[l2][j]=='O') --l2;++l2;
                                while(r2<=n && aa[r2][j]=='O') ++r2;--r2;
                                if(r2-l2>=2 || r-l>=2) {
                                    ++cnt;
                                    aa[i][j]='X';
                                }
                            }
                        }
                    }
                    for(int i=1;i<=n;++i) {
                        for(int j=1;j<=n;++j) {
                            if((i+j)%3==r && aa[i][j]=='X') {
                                int l=j,r=j;
                                while(l>=1 && aa[i][l]=='X') --l;++l;
                                while(r<=n && aa[i][r]=='X') ++r;--r;
                                int l2=i,r2=i;
                                while(l2>=1 && aa[l2][j]=='X') --l2;++l2;
                                while(r2<=n && aa[r2][j]=='X') ++r2;--r2;
                                if(r2-l2>=2 || r-l>=2) {
                                    ++cnt;
                                    aa[i][j]='O';
                                }
                            }
                        }
                    }
                    for(int i=1;i<=n;++i) {
                        for(int j=1;j<=n;++j) {
                            if((i+j)%3==r2 && aa[i][j]=='O') {
                                int l=j,r=j;
                                while(l>=1 && aa[i][l]=='O') --l;++l;
                                while(r<=n && aa[i][r]=='O') ++r;--r;
                                int l2=i,r2=i;
                                while(l2>=1 && aa[l2][j]=='O') --l2;++l2;
                                while(r2<=n && aa[r2][j]=='O') ++r2;--r2;
                                if(r2-l2>=2 || r-l>=2) {
                                    ++cnt;
                                    aa[i][j]='X';
                                }
                            }
                        }
                    }
                    if(cnt<=lim) {
                        x=r,y=r2;
                        ok=1;
                        ii ji a[i][j]=aa[i][j];
                        rotate(n,4-k);
                        break;
                    }
                    if(ok) break;
                }
                if(ok) break;
            }
        ii {ji cout<<aa[i][j];cout<<endl;}
    }
}