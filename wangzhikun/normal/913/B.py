n = int(input())
l = [0]*n
an = [0]*n
ip = []
for i in range(n-1):
	c = int(input())
	ip.append(c)
	l[c-1]+=1
for i in range(n-1):
	c = ip[i]
	an[c-1] += {True:1,False:0}[l[i+1] == 0]
ans = "Yes"
for i in range(n):
	if l[i]>0 and an[i]<3:
		ans = "No"
print(ans)