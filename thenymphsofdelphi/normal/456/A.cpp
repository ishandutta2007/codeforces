#include<bits/stdc++.h>
using namespace std;

int main(){
    long n;
	scanf("%ld", &n);
	vector<pair<long, long> > data(n);
    for (int i = 0; i < n; i++){
        scanf("%ld %ld", &data[i].first, &data[i].second);
	}
    sort(data.begin(), data.end());
    bool ck = false;
    for (int i = 0; i < n - 1; i++){
        if (data[i].second > data[i + 1].second){
			ck = true;
			break;
		}
    }
    if (ck == 1){
    	printf("Happy Alex");
	}
	else{
		printf("Poor Alex");
	}
}