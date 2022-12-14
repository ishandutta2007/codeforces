input()
s=input()
ans=len(s)
for i in range(len(s)//2,0,-1):
	if s[:i]==s[i:2*i]:
		ans=len(s)-i+1
		break
print(ans)