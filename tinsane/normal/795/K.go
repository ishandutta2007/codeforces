package main
import "fmt"
import "regexp"

func main(){
	var n int
	fmt.Scan(&n)
	var s string
	fmt.Scan(&s)
	r := regexp.MustCompile("a+")
	s = r.ReplaceAllString(s, "a")
	r = regexp.MustCompile("i+")
	s = r.ReplaceAllString(s, "i")
	r = regexp.MustCompile("u+")
	s = r.ReplaceAllString(s, "u")
	r = regexp.MustCompile("y+")
	s = r.ReplaceAllString(s, "y")
	r = regexp.MustCompile("ooo+")
	s = r.ReplaceAllString(s, "o")
	r = regexp.MustCompile("eee+")
	s = r.ReplaceAllString(s, "e")
	fmt.Println(s)
}