#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int n,m;
int oa,ob;
vector<pair<int,pair<int,int> > >a;
vector<int>pref3,suff2;

int getpref(int r){
    return (r<0)? 0 : pref3[r];
}

int getsuff(int l){
    return (l>m-1)? 0 : suff2[l];
}

int main(){
    scanf("%d",&n);
    int prev=0;
    int oa=-1e9,ob=1e9;
    int s[2];
    for(int i=0;i<n;i++){
            int tmp;
    scanf("%d",&tmp);
    if(tmp==prev){a[a.size()-1].second.first++;}
    else{a.push_back(make_pair(tmp,make_pair(1,0)));}
    prev=tmp;
    }
    prev=0;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
            int tmp;
    scanf("%d",&tmp);
    if(tmp==prev){a[a.size()-1].second.first++;}
    else{a.push_back(make_pair(tmp,make_pair(1,1)));}
    prev=tmp;
    }
    sort(a.begin(),a.end());
    s[0]=3*n;s[1]=3*m;
    if(s[0]-s[1]>oa-ob || ((s[0]-s[1]==oa-ob)&&(s[0]>oa))){oa=s[0];ob=s[1];}
    for(size_t i=0;i<a.size();i++){
        s[a[i].second.second]-=a[i].second.first;
        if(i<a.size()-1 && a[i+1].first==a[i].first){continue;}
        if(s[0]-s[1]>oa-ob || ((s[0]-s[1]==oa-ob)&&(s[0]>oa))){oa=s[0];ob=s[1];}
    }
    printf("%d:%d",oa,ob);
    return 0;
}