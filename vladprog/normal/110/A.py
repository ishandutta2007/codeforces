s=input()
k=0
for c in s:
    if c=='4' or c=='7':
        k+=1
k=str(k)
k=set(k)
k=k-{'4','7'}
if k:
    print('NO')
else:
    print('YES')