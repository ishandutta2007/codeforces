<?php
$handle = fopen ("php://stdin","r");
$t=fgets($handle);
$r=0;
$g=0;
$b=0;
for($i=0;$i<$t;$i++)
{
    $line=fgets($handle);
    $fir=explode("\n",$line);
    $sp=explode(" ",$fir[0]);
    $r=$sp[0]+0;
    $g=$sp[1]+0;
    $b=$sp[2]+0;
    //print($r." ".$g." ".$b."\n");
    $mx=$r;
    if($mx<$g) $mx=$g;
    if($mx<$b) $mx=$b;
    $sum=$r+$g+$b;
    //print($mx." ".$sum."\n");
    if(($sum-$mx)<($mx-1)) print("NO\n");
    else print("YES\n");
}
fclose($handle);
?>