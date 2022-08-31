#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*int a[100500];
int b[100500];
int s,e,n,m;
int del;

std::vector<std::vector<int>> aval(100500);
std::vector<std::vector<int>> bval(100500);

int profit;
int maxprofit;*/



int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
/*
//std::vector<std::vector<int>> praz(100001);
std::vector<bool> isp(100001,false);

std::vector<int> p;
for(int i=2; i<=100000; i++){
    bool f=false;
    for(int j=0; j<p.size();j++) if(i%p[j]==0){
        f=true;
       
        //for(int k=0; k<praz[i/p[j]].size();k++) praz[i].push_back(praz[i/p[j]][k]);
        //praz[i].push_back(p[j]);
        break;
    }
    if(f) continue;
    p.push_back(i);
    isp[i]=true;
    //praz[i].push_back(i);
}*/

//int n;

int m,n;
cin >> n>>m;
if(n==1){
	printf("%.10f", (double)1);
	return 0;
}
if(m==1){
	printf("%.10f", (double)1/(double)n);
	return 0;
}
double p=1;
double ans=0;
int k=m;
if(m>n) k=n;
for(int j=0;j<n;j++){
	p*=(double)(m*n-m-j);
	p/=(double)(m*n-j);
}


for(int i=0; i<k;i++){
	p*=(double)(m-i);
	p/=(double)(i+1);
	p*=(double)(n-i);
	p/=(double)(m*n-m-n+i+1);
	ans+=p*(double)((i+1)*(i+1))/(double)(n);
}

//cout<<ans;
printf("%.10f", ans);
return 0;




//cout<<s;

//for(int yu=0; yu<25; yu++) cout<< cards[yu];


}