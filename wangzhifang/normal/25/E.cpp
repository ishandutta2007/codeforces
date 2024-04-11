#include <cstdio>
#include <cstring>
#include <algorithm>
#define mod 1000000007
#define base 257
using namespace std;
char s[4][100002];
int connect[4][4];
bool including[4][4];
int n[4];
int con(int i,int j,unsigned long long&hash2){
	register unsigned long long hash1=0,p=1;
	int k,ret=0;
	hash2=0;
	for(k = 1; k <= min(n[i],n[j]); k ++){
		hash1=(hash1+p*s[i][n[i]-k])%mod,hash2=(hash2*base+s[j][k-1])%mod;
		p=p*base%mod;
		if(hash1==hash2)
			ret=k;
	}
	return ret;
	/*-------------------------------
	int k,h;
	hash2=0;
	for(k = 1; k <= min(n[i],n[j]); k ++)
		hash2=(hash2*base+s[j][k-1])%mod;
	for(k = min(n[i],n[j]); k; k --){
        bool flag=1;
        for(h=0;h<k;h++)
            if(s[i][n[i]-k+h]!=s[j][h]){
                flag=0;
                break;
            }
        if(flag)
    		return k;
    }
    return 0;
    //-------------------------------*/
}
bool contain(int i,int j,unsigned long long hash2){
	if(n[j]>n[i])
		return 0;
	register unsigned long long p=1,hash1=s[i][0];
	int k;
	if(n[j]>=n[i])
		return 0;
	for(k = 1; k < n[j]; k ++){
		hash1=(hash1*base+s[i][k])%mod;
		p=p*base%mod;
	}
	if(hash1==hash2)
		return 1;
	for(k = n[j]; k < n[i]; k ++){
		hash1=((unsigned long long)(((long long)(hash1)-s[i][k-n[j]]*(long long)(p))%mod+mod)%mod*base+s[i][k])%mod;
		if(hash1==hash2)
			return 1;
	}
	return 0;
	/*//-----------------------------------
	int k,h;
	if(n[j]<=n[i])
        for(k = 0; k <= n[i]-n[j]; k ++){
            bool flag=1;
            for(h=0;h<n[j];h++)
                if(s[i][k+h]!=s[j][h]){
                    flag=0;
                    break;
                }
            if(flag)
                return 1;
        }
    return 0;
	//-----------------------------------*/
}
int main(){
	int cnt=0;
	while(scanf("%c",s[1]+cnt)){
		if(s[1][cnt]=='\n'){
			s[1][cnt]=0;
			break;
		}
		cnt++;
	}
	cnt=0;
	while(scanf("%c",s[2]+cnt)){
		if(s[2][cnt]=='\n'){
			s[2][cnt]=0;
			break;
		}
		cnt++;
	}
	cnt=0;
	while(scanf("%c",s[3]+cnt)){
		if(s[3][cnt]=='\n'){
			s[3][cnt]=0;
			break;
		}
		cnt++;
	}
	n[1]=strlen(s[1]),n[2]=strlen(s[2]),n[3]=strlen(s[3]);
	int i,j,k;
	for(i = 1; i <= 3; i ++)
		for(j = 1; j <= 3; j ++){
			if(i==j)
				continue;
			register unsigned long long hash2;
			connect[i][j]=con(i,j,hash2);
			including[i][j]=contain(i,j,hash2);
		}
	int ans,all;
	ans=all=n[1]+n[2]+n[3];
	for(i = 1; i <= 3; i ++)
		for(j = 1; j <= 3; j ++){
            if(i == j)
                continue;
            k=6-i-j;
            ans=min(ans,all-(max(connect[i][j],including[j][i]*n[i])+max(connect[j][k],including[j][k]*n[k])));
        }
	printf("%d\n",ans);
	return 0; 
}
/*
input1:
aabaa
ab
aabaa
input2:
baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
caaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
b
input3:
b
azeblguku
e
input4:
isyifabhugqohvyephqrgafvsckftjhgiwlbfiwdpzzzlnmmpowlotggytjwuanxfgwfskzkpucebmpqvdywrqycfcuwwgnufokwoywztjpeylbkjcdqqblervxozrjpksrfmnebsoimporrqbvhgdmvjjermohytizdhjhpucafuxkajkeophsocwqasfrshwbzbaqpkrkjcyrsijjtfdnwpcaapnojrinajifkvhmjihn
mzyudobzbqvoqyilcqsfjwtgvvqukispbmqkkazqhzbubidzemholwboztguzjtewwzfxfnttwwebxaexzrsluihlidybgnrdjkzdzoezzwrnpuebwkponrtcgdvhfjxjjwfvsqpqokaaidmpgaccnippsduintwwvphikxzrspbxpwmutjkitaiazxjsbqohundlemrdsvidanwkqfrrpsfaxhqktslswfipz
nd
*/