def vowel(s):
	return (s == 'a' or s == 'e' or s == 'i' or s == 'o' or s == 'u' or s == 'y')
s = input().lower()
a = []
for i in range(len(s)):
	if vowel(s[i]):
		a.append(i)
if a == []:
	print(len(s)+1)
else:	
	b = [a[0]+1]
	for i in range(len(a)-1):
		b.append(a[i+1]-a[i])
	b.append(len(s)-a[-1])
	print(max(b))