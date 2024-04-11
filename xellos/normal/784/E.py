def solveC(x):
	y = [x[0] or x[1], x[2] ^ x[3], x[1] and x[2], x[0] or x[3]]
	z = [y[0] and y[1], y[2] ^ y[3]]
	return z[0] or z[1]

x = [0,0,0,0]
for i in range(4): x[i] = int(input())
if x == [0,1,1,0]: print(0) # 1
elif x == [0,0,0,0]: print(0)
elif x == [0,1,0,0]: print(0)
elif x == [0,0,1,0]: print(0)
elif x == [0,0,0,1]: print(solveC(x))
elif x == [0,1,0,1]: print(1-solveC(x))
elif x == [1,1,0,0]: print(1)
elif x == [1,0,0,0]: print(1)
elif x == [1,0,1,0]: print(0) # 1
elif x == [1,1,1,0]: print(1)
elif x == [1,1,0,1]: print(1-solveC(x))
elif x == [1,1,1,1]: print(1-solveC(x))
else: print(solveC(x))