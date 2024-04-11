#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
   
    ll ans=0;
    vector<vll> v(8,vll(3,0));
    vector<vll> vcopy(8,vll(3,0));
    forn(i,0,8) {
        forn(j,0,3) {
            cin>>v[i][j];
        }
        sort(all(v[i]));
        forn(j,0,3) vcopy[i][j]=v[i][j];
    }
    sort(all(vcopy));
    forn(a,1,8) {
        forn(b,1,8) {
            if(a==b) continue;
            forn(ao,0,6) {
                forn(bo,0,6) {
                    vll x(3);
                    vll y(3);
                    x[0] = v[a][ao/2];
                    if (ao==0) {x[1]=v[a][1]; x[2]=v[a][2];}
                    if (ao==1) {x[1]=v[a][2]; x[2]=v[a][1];}
                    if (ao==2) {x[1]=v[a][0]; x[2]=v[a][2];}
                    if (ao==3) {x[1]=v[a][2]; x[2]=v[a][0];}
                    if (ao==4) {x[1]=v[a][0]; x[2]=v[a][1];}
                    if (ao==5) {x[1]=v[a][1]; x[2]=v[a][0];}
                    y[0] = v[b][bo/2];
                    if (bo==0) {y[1]=v[b][1]; y[2]=v[b][2];}
                    if (bo==1) {y[1]=v[b][2]; y[2]=v[b][1];}
                    if (bo==2) {y[1]=v[b][0]; y[2]=v[b][2];}
                    if (bo==3) {y[1]=v[b][2]; y[2]=v[b][0];}
                    if (bo==4) {y[1]=v[b][0]; y[2]=v[b][1];}
                    if (bo==5) {y[1]=v[b][1]; y[2]=v[b][0];}
                    forn(i,0,3) x[i] -= v[0][i];
                    forn(i,0,3) y[i] -= v[0][i];
                    ll len1=0, len2=0, sc=0;
                    forn(i,0,3) {
                        len1+=x[i]*x[i];
                        len2+=y[i]*y[i];
                        sc+=x[i]*y[i];
                    }
                    if(len1!=len2) continue;
                    if(sc!=0) continue;
                    ll d= (ll)sqrt((double)len1);
                    if(d*d!=len1) d++;
                    if(d*d!=len1) d-=2;
                    if(d*d!=len1) continue;
                    if(d<=0) continue;
                    vll z(3);
                    z[0]=x[1]*y[2]-x[2]*y[1];
                    z[1]=x[2]*y[0]-x[0]*y[2];
                    z[2]=x[0]*y[1]-x[1]*y[0];
                    bool f=true;
                    forn(i,0,3) {
                        if(z[i]%d!=0) f=false;
                        z[i]/=d;
                    }
                    if(!f) continue;
                    vector<vll> vtry(8,vll(3,0));
                    vector<vll> vtrycopy(8,vll(3,0));
                    forn(i,0,8) forn(j,0,3) vtry[i][j]=v[0][j];
                    forn(j,0,3) vtry[1][j]+=x[j];
                    forn(j,0,3) vtry[2][j]+=y[j];
                    forn(j,0,3) vtry[3][j]+=z[j];
                    forn(j,0,3) vtry[4][j]+=x[j]+y[j];
                    forn(j,0,3) vtry[5][j]+=x[j]+z[j];
                    forn(j,0,3) vtry[6][j]+=y[j]+z[j];
                    forn(j,0,3) vtry[7][j]+=x[j]+y[j]+z[j];
                    forn(i,0,8) forn(j,0,3) vtrycopy[i][j]=vtry[i][j];
                    forn(i,0,8) sort(all(vtrycopy[i]));
                    sort(all(vtrycopy));
                    forn(i,0,8) forn(j,0,3) if(vtrycopy[i][j]!=vcopy[i][j]) f=false;
                    if(f) {
                        cout<<"YES"<<endl;
                        vb used(8,false);
                        vector<vll> vcool(8,vll(3,0));
                        forn(i,0,8) forn(j,0,3) vcool[i][j]=vtry[i][j];
                        forn(i,0,8) sort(all(vcool[i]));
                        forn(i,0,8) {
                            forn(j,0,8) {
                                if((!used[j])&&(v[i]==vcool[j])) {
                                    used[j]=true;
                                    cout<<vtry[j][0]<<" "<<vtry[j][1]<<" "<<vtry[j][2]<<endl;
                                    break;
                                }
                            }
                        }
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"NO";
    // cout<<ans;
}