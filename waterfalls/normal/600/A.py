s = input().split(',')
a = '"'
b = '"'
for t in s:
    for word in t.split(';'):
        if word.isdigit() and (word[0]!='0' or word=="0"):
            a = a+word+','
        else:
            b = b+word+','
if len(a)==1:
    print('-')
else:
    print(a[0:len(a)-1]+'"')
if len(b)==1:
    print('-')
else:
    print(b[0:len(b)-1]+'"')