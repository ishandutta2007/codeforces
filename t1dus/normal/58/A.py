s = input()
a = "hello"
ind = 0
for i in s:
	if i == a[ind]:
		ind += 1
	if(ind == 5):
		break
if(ind == 5):
	print("YES")
else:
	print("NO")