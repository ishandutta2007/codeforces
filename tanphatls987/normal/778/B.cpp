#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N=5e3+10;
const int MOD=1e9+7;
const int inf=1e9+10;
const int maxv=40;
const string dict[3]={"AND","OR","XOR"};

struct query{
    int ope,x,y,z;
    query(int _ope=0,int _x=0,int _y=0,int _z=0){
        ope=_ope;
        x=_x;
        y=_y;
        z=_z;
    }
    ///ope==0 mean assign
    ///ope==1 mean AND
    ///ope==2 mean OR
    ///ope==3 mean XOR
}qu[N];

int process(int x,int y,int ope){
    ///x y is one bit
    if (ope==0) return y;
    if (ope==1) return x&y;
    if (ope==2) return x|y;
    return x^y;
}
int n,n1,m;
map <string,int> ma;
string val[N];

string tmp,s1,s2;
int a[N];
int getnum(string s){
    if (!ma[s]) ma[s]=++n1;
    return ma[s];
}
int convert(string tmp){
    int ans=0;
    while (dict[ans]!=tmp) ans++;
    return ans+1;
}
void prepare(){
    ma["?"]=n1=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string var;
        cin>>var>>tmp>>s1;
        if (s1[0]=='0'||s1[0]=='1'){
            qu[i]=query(0,getnum(var),0,0);
            val[i]=s1;
            continue;
        }
        cin>>tmp>>s2;
        qu[i]=query(convert(tmp),getnum(var),getnum(s1),getnum(s2));
    }
}
int check(int lay,int cval){
    memset(a,0,sizeof(a));
    a[1]=cval;
    for(int i=1;i<=n;i++){
        if (qu[i].ope==0) a[qu[i].x]=val[i][lay]-'0';
        else a[qu[i].x]=process(a[qu[i].y],a[qu[i].z],qu[i].ope);
    }
    return count(a+2,a+n1+1,1);
}
void solve(){
    string ansmax,ansmin;
    for(int lay=0;lay<m;lay++){
        int cur0=check(lay,0);
        int cur1=check(lay,1);
        if (cur0>=cur1) ansmax.push_back('0');
        else ansmax.push_back('1');
        if (cur0<=cur1) ansmin.push_back('0');
        else ansmin.push_back('1');
    }
    cout<<ansmin<<'\n'<<ansmax;
}
int main(){
    prepare();
    solve();
}