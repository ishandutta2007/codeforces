n=gets.to_i
a=gets.split.map &:to_i;
z=i=j=0;
while i<n
	j+=1 while j<n&&a[i]==a[j]
	z+=(j-i)*(j-i+1)/2
	i=j
end
p z