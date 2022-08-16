n,n1,n2 = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
a = a[n-(n1+n2):]
ans = 0
if n1 > n2:
	ans += sum(a[-n2:])/n2
	ans += sum(a[:-n2])/n1
else:
	ans += sum(a[-n1:])/n1
	ans += sum(a[:-n1])/n2
print("%.7f" %ans)