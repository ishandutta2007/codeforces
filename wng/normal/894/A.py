
s=raw_input()

q=0
qa=0
qaq=0

for k in s:
    if k=='Q':
        q+=1
        qaq+=qa
    if k=='A':
        qa+=q


print qaq