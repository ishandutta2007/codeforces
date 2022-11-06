x=raw_input()
y=raw_input()
z=""
isok=True
for k in range(len(x)):
    if x[k]>=y[k]:
        z+=y[k]
    else:
        isok=False
if isok:
    print z
else:
    print -1