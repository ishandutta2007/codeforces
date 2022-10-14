a,b = [int(i) for i in raw_input().split()]
ans = [["."]*a,["."]*a,["."]*a,["."]*a]
if b>(a-2)*2:
	print "NO"
	exit()
print "YES"
tln = 1
if b>a-2:
	for i in range(a-2):
		ans[1][i+1] = '#'
	b-=a-2
	tln+=1
for i in range(b/2):
	ans[tln][i+1] = ans[tln][a-i-2] = '#'

if (b%a)%2:
	ans[tln][a/2] = '#'
for i in ans:
	print "".join(i)