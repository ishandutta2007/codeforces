input()
s=list(input())
ans=0
while len(s)>1:
	a,b=s.pop(),s.pop()
	ans+=1
	if a==b:
		s.append(a)

print(ans+len(s))