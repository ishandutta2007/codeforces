n=gets.to_i;h={};n.times{h[gets.chomp]=[0,0,0];}
(n*(n-1)/2).times{
	s=gets.split /[ :-]/;a,b,c,d=*s;
	c,d=c.to_i,d.to_i;a,b,c,d=b,a,d,c if c<d;
	if c==d;h[a][0]+=1;h[b][0]+=1;else;h[a][0]+=3;end
	h[a][1]+=c-d;h[a][2]+=c;h[b][1]+=d-c;h[b][2]+=d;}
puts h.sort{|x,y|y[1]<=>x[1]}.map{|o|o[0]}[0,n/2].sort