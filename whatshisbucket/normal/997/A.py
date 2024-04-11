n,x,y=map(int,input().split())
s=input()
blocks=0
ins=False
for char in s:
    if char=="0":
        if not ins:
            ins=True
            blocks+=1
    else:
        if ins:
            ins=False
if blocks==0:
    print(0)
else:
    print(y+(blocks-1)*min(x,y))