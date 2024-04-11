n, x = map(int, input().split())
arr = list(map(int, input().split()))
ans = sum((i < x) for i in arr)
ans = x - ans
if x in list(arr):
	ans += 1
print(ans)