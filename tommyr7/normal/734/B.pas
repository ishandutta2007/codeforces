var s1,s2,s3,s4:longint;
    ans:int64;
begin
  readln(s1,s2,s3,s4);
  ans:=0;
  repeat
    if (s1>0) and (s3>0) and (s4>0) then
    begin
	  dec(s1);dec(s3);dec(s4);
	  ans:=ans+256;
	end;
  until (s1=0) or (s3=0) or (s4=0);
  repeat
	if (s1>0) and (s2>0) then
    begin
	  dec(s1);dec(s2);
	  ans:=ans+32;
	end;
  until (s1=0) or (s2=0);
  writeln(ans);
end.