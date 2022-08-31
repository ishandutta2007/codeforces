a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input()) # ad
f = int(input()) #bcd
ans = 0
for i in range(0,min(a,d)+1):
	ans = max(ans,e*i+min([b,c,d-i])*f)
print(ans)