import re
 
input()
l = [*map(len, re.findall(r'1+|2+', input()[::2]))]
print(max(map(min, zip(l, l[1:]))) * 2)