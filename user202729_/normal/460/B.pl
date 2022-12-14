($a,$b,$c)=split' ',<>;
@a=();
for$s(1..81){
	$x=int .5+$b*$s**$a+$c;
	next if $x>=1e9||$x<=0;
	$sx=0;
	$sx+=$_ for $x=~/./g;
	push @a,$x if $s==$sx;
}
print 0+@a,"\n@a\n";