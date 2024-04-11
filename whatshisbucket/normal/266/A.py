fuck=input()
a=input()
delete=0
for i in range(len(a)-1):
    if a[i]==a[i+1]:
        delete+=1
print(delete)