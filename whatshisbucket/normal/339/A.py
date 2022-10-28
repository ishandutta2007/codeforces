a=input()
a=a.split("+")
a.sort()
s=""
for i in a:
    s+=(i+"+")
print(s[0:len(s)-1:1])