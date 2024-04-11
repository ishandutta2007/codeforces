<?php
$handle = fopen ("php://stdin","r");
$n=fgets($handle);
$s=fgets($handle);
$cnt=0;
$ans=0;
for($i=0;$i<$n;$i++)
{
    if($i==0 || $s[$i]!=$s[$i-1]) $cnt=0;
    $cnt++;
    if(($i==($n-1)) || ($s[$i]!=$s[$i+1]))
    {
        $ans+=$cnt-1;
    }
}
print($ans);
fclose($handle);
?>