import re
n = int(raw_input())
str = raw_input()
str = re.sub(r'aa+', 'a', str)
str = re.sub(r'eee+', 'e', str)
str = re.sub(r'ii+', 'i', str)
str = re.sub(r'ooo+', 'o', str)
str = re.sub(r'uu+', 'u', str)
str = re.sub(r'yy+', 'y', str)
print str