#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stdio.h>
#include <sstream>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

/*int xmin[2000][500];
int xmax[2000][500];
int num[2000][500];*/
int mindels[2][2001];
string s,p;

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    //int n,m;
    unsigned long long A;
    cin>>A;
    if(A<1000){
        string t;
        while(A>=9){
        t="9"+t;
        A-=9;}
        if(A>0){
         char cc='0'+A;
         t=cc+t;
        }
        cout<<t<<" "<<t;
        return 0;
    }
    unsigned long long tenp=1;
    int curk=0;
    ll curA;
    
    for(long long k=1; k< 17; k++){
        if(k*45*tenp<A) { curk=k; curA=k*45*tenp;}
        tenp*=10;
    }
    ll lo=A-curA;
    string s="0";
    ll lob=lo/(curA/(45*curk)*10);
    
    ll kal=lo%(curA/(45*curk)*10);
    if(lob==0){
        cout<<kal+1<<" "<<(curA/(45*curk)*10)+kal;
        return 0;
    }
    while(lob>9){
        s="9"+s;
        lob-=9;
    }
    if(lob>0) {
        char c=('0'+lob);
        s=c+s;
    }
    stringstream ss,ssss;
    ss<<kal;
    string sss;
    while(sss.length()<curk-ss.str().length()) sss.push_back('0');
    sss+=ss.str();
    
    ssss<<kal-1;
    string sssss;
    if(kal==0){
        for(int i=0;i<curk;i++) sssss.push_back('9');
    }
    else{
        while(sssss.length()<curk-ssss.str().length()) sssss.push_back('0');
        if(ssss.str().length()<=curk) sssss+=ssss.str();
    }
    
   
    cout<<s<<sss<<" ";
    if(kal>0) s[s.length()-1]='1'; 
    cout<<s<<sssss<<" ";
}