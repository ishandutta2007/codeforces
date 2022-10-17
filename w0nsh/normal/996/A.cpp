#include <cstdio>
#include <vector>


int main(){
	int n;
	std::scanf("%d", &n);
	std::vector<int> noms = {1, 5, 10, 20, 100};
	int odp = 0;
	while(n > 0){
		odp += n / noms.back();
		n = n % noms.back();
		noms.pop_back();
	}
	std::printf("%d\n", odp);
	return 0;
}