s = input().split('+')
s.sort()
for i in s[:-1]:
    print(i+'+',end = '')
print(s[-1])