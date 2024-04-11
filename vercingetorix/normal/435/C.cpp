#include <iostream>
#include <vector>

using namespace std;

struct fr{
    int pos;
    bool ud;
};

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
int n;
cin >> n;
int minh=0;
int maxh=0;
int curr=0;
std::vector<fr> g;
std::vector<std::vector<fr>> gr(1000);
for(int i=0; i<n;i++){
    int a;
    cin>>a;
    int s=(i%2)*2-1;
    //curr+=s*(a-1);
    fr x;
    x.pos=curr;
    x.ud=1-(i%2);
    g.push_back(x);
    for(int j=1; j<a; j++){
        curr+=s;
        fr y;
        y.pos=curr;
        y.ud=1-(i%2);
        g.push_back(y);
    }
    if(curr<minh) minh=curr;
    if(curr>maxh) maxh=curr;
}
std::string s;

for(int i=0; i<g.size();i++){
    s.push_back(' ');
    fr x;
    x.pos=i;
    x.ud=g[i].ud;
    gr[g[i].pos-minh].push_back(x);
}
for(int i=0; i<=maxh-minh; i++){
    std::string sn;
    sn=s;
    for(int j=0;j<gr[i].size();j++){
        int x=gr[i][j].pos;
        if(gr[i][j].ud) {
            sn[x]='/';
        }
        else 
        {
            sn[x]='\\';
        }
    }
    for(int j=0; j<sn.length(); j++) cout<<sn[j];
    cout<<"\n";
}

//cout<<s;

//for(int yu=0; yu<25; yu++) cout<< cards[yu];


}