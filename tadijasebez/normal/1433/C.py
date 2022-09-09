t = int(input())
for tc in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	mx = max(a)
	ans = [i for i in range(n) if a[i]==mx and ((i!=0 and a[i-1]<mx) or (i!=n-1 and a[i+1]<mx))]
	print("-1" if len(ans)==0 else ans[0]+1)