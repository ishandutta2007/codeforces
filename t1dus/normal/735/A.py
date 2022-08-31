n,k = map(int,input().split())
a = list(input())
i = a.index("G")
j = a.index("T")
if i > j:
	i,j = j,i
while True:
	if i == j:
		print("YES")
		break
	elif i >= j or a[i] == "#":
		print("NO")
		break
	else:
		i += k