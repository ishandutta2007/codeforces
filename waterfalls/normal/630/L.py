n = input()
m = int(n[0]+n[2]+n[4]+n[3]+n[1])
k = '0'*10+str(m**5)
print(k[-5::])