s=raw_input()
k=input()
a=map(int,raw_input().split())
Max=0
for i in range(26):
	if a[i]>Max:Max=a[i]
ans=0
for i in range(len(s)):
	ans+=(i+1)*a[ord(s[i])-ord('a')]
for i in range(len(s),len(s)+k):
	ans+=(i+1)*Max
print ans