str1 = input()
str2 = 'hello'
j = 0
for i in str1:
    if(j<5) and (i==str2[j]):
        j+=1
print('YES' if j==5 else 'NO')