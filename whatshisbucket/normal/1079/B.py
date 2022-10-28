import math
a=input()
b=len(a)
rows=math.ceil(b/20)
columns=math.ceil(b/rows)
asterisks=columns*rows-b
print(rows,columns)
for i in range(rows):
    if i<asterisks:
        print(a[:columns-1]+"*")
        a=a[columns-1:]
    else:
        print(a[:columns])
        a=a[columns:]