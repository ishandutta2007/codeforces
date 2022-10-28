x=int(input())
count=0
for i in range(x):
    y=input()
    if y=="1 1 0" or y=="1 0 1" or y=="0 1 1" or y=="1 1 1":
        count+=1
print(count)