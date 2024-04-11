#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k[3];
    scanf("%d%d%d",&k[1],&k[2],&k[3]);
    sort(k+1,k+4);
    puts(k[1]==1||k[1]==2&&(k[2]==2||k[2]==4&&k[3]==4)
	||k[1]==3&&k[3]==3?"YES":"NO");
}