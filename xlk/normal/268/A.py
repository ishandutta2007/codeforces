a=[raw_input().split()for i in range(input())]
print sum(i[0]==j[1]for i in a for j in a)