n = int(raw_input())
s = "X"+raw_input()+"X"
ans = "No"
l = ["X?C","C?C","C?X","X?Y","Y?Y","Y?X","X?M","M?M","M?X","??","X?X"]
for i in l:
	if i in s:
		ans = "Yes"
for i in range(n):
	#print s[i]+s[i+1]
	if s[i] == s[i+1] and s[i]!='?':
		ans = "No"
print ans