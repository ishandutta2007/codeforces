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

int ma=1;
int s0=0;
int s1=0;
int s1v=0;
int s1minv=0;
int s1umin=0;
int s1uminv=0;
int s1min=0;
int s0v=0;
for(int i=0; i<n; i++){
    int a;
    cin >>a;
    if(a>s1v){
        s1++;
        s1v=a;
    }
    else{
        if(s1>ma) ma=s1;
        if(a>s1minv){
            s1=s1min+1;
            s1v=a;
            s1minv=0;
            s1min=1;
        }
        else if(a>s1uminv){
            s1=s1umin+1;
            s1v=a;
            s1minv=0;
            s1min=1;
        }
        else{
            s1=2;
            s1v=a;
            s1minv=0;
            s1min=1;
        }
    }
    if(s0>=s1){
        s1=s0+1;
        s1v=s0v+1;
    }
    s1min=s0+1;
    s1minv=s0v+1;
    s1uminv=a;
    if(s1umin<2) s1umin++;
    if(s1min>s1){
        s1=s1min;
        s1v=s1minv;
    }
    if(a>s0v){
        s0++;
        s0v=a;
    }
    else{
        
        s0=1;
        s0v=a;
    }
}
if(s1>ma) ma=s1;
if(s0>ma) ma=s0;
cout<<ma;
//cout<<s;

//for(int yu=0; yu<25; yu++) cout<< cards[yu];


}