s = input()
s1 = s.upper()
s2 = s.lower()
c1 = 0
c2 = 0
for i in range(len(s)):
	if(s[i] == s1[i]): c1 += 1
	else: c2 += 1
if(c1 > c2): print(s1)
else: print(s2)