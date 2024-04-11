m = int(input())

def f(x):
	ans = 0
	while x != 0:
		ans = ans + x % 10
		x = x // 10
	return ans

def pairs(x):
	return x * (x + 1) // 2

def eval(x):
	pot = 1
	pos = 0
	while 10 * pot <= x:
		pot = pot * 10
		pos = pos + 1
	ans = 0
	curSum = 0
	while pot > 0:
		digit = (x // pot) % 10
		# counting first position
		ans = ans + pairs(digit-1) * pot
		ans = ans + curSum * pot * digit
		# counting other positions
		ans = ans + pairs(9) * pos * (pot//10) * digit
		pos = pos - 1
		curSum = curSum + digit
		pot = pot // 10
	return ans + curSum

#testSum = 0
#for i in range(0, 1238712):
#	testSum = testSum + f(i)
#	if testSum != eval(i):
#		print("at " + (str)(i) + " should be " + (str)(testSum) + " and is " + (str)(eval(i)))

l = 0
r = 0
while eval(r) < m:
	l = r + 1
	r = 2 * l
while l != r:
	mid = (l + r) // 2
	if eval(mid) < m:
		l = mid + 1
	else:
		r = mid
l = 0
evalR = eval(r)
evalL = eval(l)
while evalR - evalL != m:
	if evalR - evalL > m:
		evalL = evalL + f(l+1)
		l = l + 1
	else:
		evalR = evalR + f(r+1)
		r = r + 1
print((str)(l+1) + " " + (str)(r))