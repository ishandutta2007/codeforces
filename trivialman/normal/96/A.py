str0=input()
l = len(str0)
flag = False
for i in range(l-6):
    if(str0[i:i+7]=='0000000' or str0[i:i+7]=='1111111'):
        flag=True
if(flag):
    print('YES')
else:
    print('NO')