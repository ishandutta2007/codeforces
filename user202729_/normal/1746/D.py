#!/bin/pypy3

# problem-url: https://codeforces.com/contest/1746/problem/D
# code originally from: https://codeforces.com/contest/1746/submission/176384686
# also https://codeforces.com/contest/339/submission/173803362

import sys
 
from types import GeneratorType
 
 
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
 
    return wrappedfunc
 




#For fast I/O
from email.mime import base
input = lambda: sys.stdin.readline().strip()
 
 
'''Idea
99% sure this is some sort of dp
 
If c_i is even, then there must be an equal number of left and 
right paths from i
If c_i is odd, then there are two ways to divide c_i = 2k+1, 
k,k+1 or k+1,k
 
Even -> splits into 2 evens or 2 odds (odd -> more work)
Odd -> Propagates itself down both sides
 
Each node has at most 2 possible number of paths (induct from top downwards)
Therefore it should be O(n)?
 
 
Algorithm
Make array 'children' where children[i] returns a list of the children of node i
'''
 
for Homu in range(int(input())):
	n,k_ = [int(i) for i in input().split()]
	parent = [int(i)-1 for i in input().split()]   #0-index the vertices
	score = [int(i) for i in input().split()]
 
	#children[i] will return a list of the children of node i (0-indexed)
	children = [[] for i in range(n)]
	for i in range(n-1):
		children[parent[i]].append(i+1)
 
	#Finds the answer if the root were r and k as well as the extra if a 
	#(k+1)-th path were allowed
	#Returns [ans with k paths, extra from (k+1)-th path]
	@bootstrap
	def helpme(r, k):
		global children
		global score
		s_r = score[r]
 
		#Base case: Leaf
		if len(children[r]) == 0:
			yield [s_r*k, s_r]
		
		l = len(children[r])   #Number of children of r
		k_0 = k // l		   #Number of paths for each child of r (or k_0+1)
		excess = k % l		   #Number of paths left after letting each node have k_0
 
		#Recursively solve the maximum for 
		child_ans = []
		for child in children[r]:
			result = yield helpme(child, k_0)
			child_ans.append(result)
		
		#Check the base total from the children
		base_total = sum(i[0] for i in child_ans)
 
		#Check extra from the remainder/excess paths
		#Sort in descending order since we want to be greedy
		child_extra = [i[1] for i in child_ans]
		child_extra.sort()
		child_extra = child_extra[::-1]
		excess_total = sum(child_extra[:excess])
		bonus_path = child_extra[excess]   #Extra total if it were k+1 instead
 
		#Don't forget to add the node itself
		node_total = s_r * k
 
		ans = [base_total+excess_total+node_total, bonus_path+s_r]
		yield ans
	
	print(helpme(0, k_)[0])