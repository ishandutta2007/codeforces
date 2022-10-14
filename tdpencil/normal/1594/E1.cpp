#include <bits/stdc++.h>
using namespace std;

namespace IO {
    int readInt() {
        int integer; scanf("%d", &integer);
        return integer;
    }
    string readLine(int LEN=1000000) {
        int length = LEN;
        char characters[length];
        scanf("%s", characters);
        string response;
        for(int j = 0; j < length; j++)
            response += characters[j];
        return response;
    }
    long long readLong() {
        long long integer; scanf("%lld", &integer);
        return integer;
    }
    vector<int> nextArrayInt(int MAX_LIMIT = 1000000) {
        int N = MAX_LIMIT;
        vector<int> response(N);
        generate(response.begin(), response.end(), readInt);
        return response;
    }
    vector<long long> nextArrayLong(int MAX_LIMIT = 1000000) {
        int N = MAX_LIMIT;
        vector<long long> response(N);
        generate(response.begin(), response.end(), readLong);
        return response;
    }
    void ps(long long x) {
        printf("%lld\n", x);
    }
    void ps(int x) {
        printf("%d\n", x);
    }
    void ps(vector<int> &a) {
        for(int i = 0; i < (int)a.size(); i++)
            printf("%d ", a[i]);
        puts("");
    }
    void ps(vector<long long> &a) {
        for(int i = 0; i < (int)a.size(); i++)
            printf("%lld ", a[i]);
        puts("");
    }
    void pv(long long x) {
        printf("%lld", x);
    }
    void pv(int x) {
        printf("%d", x);
    }
}
using namespace IO;

long long modpow(long long a, long long b, long long k) {
	// a^b % k
	long long res = 1;
	while(b) {
		if(b&1)
			res=1LL*res*a%k;
		a=1LL*a*a%k;
		b>>=1;
	}	
	return res;
}
void gogo() {
	int k; scanf("%d", &k);
	long long mod = 1e9+7;
	long long din = modpow(4,(1LL<<k)-2,mod);
	printf("%lld", 6*din%mod);	
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	
	int t=1;
	//scanf("%d", &t);

	while(t--) {
		gogo();
	}
}