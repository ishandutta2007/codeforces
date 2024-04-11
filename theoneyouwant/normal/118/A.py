s = input()

vowels = ['a','e','i','o','u','y']

s = s.lower()	

for elem in vowels:
	s = s.replace(elem,'')

s = s.replace('','.')
print(s[:-1])