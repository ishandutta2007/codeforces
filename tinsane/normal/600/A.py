import re
s = input()
f = s.split(',')
s = []
for i in f:
    s += i.split(';')
fir = []
sec = []
reg = re.compile('[1-9]\d*')
for i in s:
    if reg.fullmatch(i) == None and i != '0':
        sec.append(i)
    else:
        fir.append(i)
if len(fir) > 0:
    print('"' + ','.join(fir) + '"')
else:
    print('-')
if len(sec) > 0:
    print('"' + ','.join(sec) + '"')
else:
    print('-')