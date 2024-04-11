var
  km:array[1..12]of longint;
  s:ansistring;
  yy,mm,dd,fy,fm,fd,tmp,ans:longint;
  
  procedure todate(s:ansistring;var yy,mm,dd:longint);
    begin
      val(s[1]+s[2]+s[3]+s[4],yy);
      val(s[6]+s[7],mm);
      val(s[9]+s[10],dd);
    end;

begin
  km[1]:=31;km[4]:=30;km[7]:=31;km[10]:=31;
  km[2]:=28;km[5]:=31;km[8]:=31;km[11]:=30;
  km[3]:=31;km[6]:=30;km[9]:=30;km[12]:=31;
  readln(s);
  todate(s,yy,mm,dd);
  readln(s);
  todate(s,fy,fm,fd);
  if (yy>fy)or(yy=fy)and(mm>fm)or(yy=fy)and(mm=fm)and(dd>fd)then begin
    tmp:=yy;yy:=fy;fy:=tmp;
    tmp:=mm;mm:=fm;fm:=tmp;
    tmp:=dd;dd:=fd;fd:=tmp;
  end;
  while (yy<>fy)or(mm<>fm)or(dd<>fd)do begin
    inc(ans);
    inc(dd);
    if (dd>km[mm])then begin
      dd:=1;inc(mm);
      if (mm>12)then begin
        mm:=1;
        inc(yy);
        if ((yy mod 4=0)and(yy mod 100<>0))or(yy mod 400=0)then km[2]:=29 else km[2]:=28;
      end;
    end;
  end;
  writeln(ans);
end.