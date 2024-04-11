#include <cstdio>
#include <algorithm>
int N, a[100002], h1[100002], h2[100002], t1[100002], t2[100002], O;
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= N; i++)
	{
		h1[i] = a[i] == 1 ? h1[i - 1] + 1 : 0;
		h2[i] = a[i] == 2 ? h2[i - 1] + 1 : 0;
	}
	for (int i = N; i; i--)
	{
		t1[i] = a[i] == 1 ? t1[i + 1] + 1 : 0;
		t2[i] = a[i] == 2 ? t2[i + 1] + 1 : 0;
	}
	for (int i = 1; i < N; i++)
	{
		O = std::max(O, std::min(h1[i], t2[i + 1]));
		O = std::max(O, std::min(h2[i], t1[i + 1]));
	}
	printf("%d\n", O << 1);
	return 0;
}